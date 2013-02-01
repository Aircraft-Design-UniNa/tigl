#!/bin/bash
#
# Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
#
# Created: 2013-01-17 Martin Siggel <martin.siggel@dlr.de>
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# @brief This script creates an all-inclusive binary package for TIGL.
# It downloads the required binaries from our openbuildservice page
# and copies them into on tar.gz file

#package version and name
PACKAGE=TIGL
VERSION=2.0.4


DIST=NO_DIST
FDIST=NO_DIST
PACK_ARCH=NO_ARCH
ARCH=NO_ARCH
LIBDIR=NO_DIR
PACK_TYPE=NO_TYPE


function printUsage {
    echo "usage: build-package <distro> <arch>"
    echo
    echo "Valid distributions:"
    echo "    SLE_11         Suse Linux Enterprise 11"
    echo "    SLE_11_SP1     Suse Linux Enterprise 11 SP1"
    echo "    SLE_11_SP2     Suse Linux Enterprise 11 SP2"
    echo "    openSUSE_11.4  openSUSE 11.4"
    echo "    openSUSE_12.1  openSUSE 12.1"
    echo "    openSUSE_12.2  openSUSE 12.2"
    echo "    ubuntu_11.10   Ubuntu 11.10"
    echo "    ubuntu_12.04   Ubuntu 12.04"
    echo "    ubuntu_12.10   Ubuntu 12.10"
    echo "    fedora_17      Fedora 17"
    echo "    rhel_6         Red Hat Enterprise Linux 6"
    echo "    centos_6       CentOS 6"
    echo
    echo "Valid architectures:"
    echo "    x86_64        64 Bit"
    echo "    i386          32 Bit"
    echo
}

function checkArguments {

    # check number of args
    if [ $# -ne 2 ]
    then
	printUsage
        exit 1
    fi

    tmp_dist=$1
    tmp_arch=$2
    #check arch
    if [[ $tmp_arch != i386 && $tmp_arch != x86_64 ]]; then
	echo "Error: Unsupported architecture:" $tmp_arch
	echo
	printUsage
	exit 2
    fi

    LIBDIR=lib

    #check dist
    if [[ $tmp_dist == SLE_11_SP1 ]]; then
    	DIST=SLE_11_SP1
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i586
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == SLE_11_SP2 ]]; then
    	DIST=SLE_11_SP2
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i586
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == SLE_11 ]]; then
    	DIST=SLE_11
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i586
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == openSUSE_11.4 ]]; then
    	DIST=openSUSE_11.4
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i586
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == openSUSE_12.1 ]]; then
    	DIST=openSUSE_12.1
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i586
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == openSUSE_12.3 ]]; then
    	DIST=openSUSE_12.2
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i586
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == rhel_6 ]]; then
    	DIST=RedHat_RHEL-6
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i686
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
   elif [[ $tmp_dist == centos_6 ]]; then
    	DIST=CentOS_CentOS-6
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i686
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
   elif [[ $tmp_dist == fedora_17 ]]; then
    	DIST=Fedora_17
	PACK_TYPE=rpm
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i686
        else
            PACK_ARCH=x86_64
            LIBDIR=lib64
	fi
    elif [[ $tmp_dist == ubuntu_11.10 ]]; then
    	DIST=xUbuntu_11.10
	PACK_TYPE=deb
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i386
        else
            PACK_ARCH=amd64
	fi
    elif [[ $tmp_dist == ubuntu_12.04 ]]; then
    	DIST=xUbuntu_12.04
	PACK_TYPE=deb
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i386
        else
            PACK_ARCH=amd64
	fi
    elif [[ $tmp_dist == ubuntu_12.10 ]]; then
    	DIST=xUbuntu_12.10
	PACK_TYPE=deb
	if [[  $tmp_arch == i386 ]]; then
	    PACK_ARCH=i386
        else
            PACK_ARCH=amd64
	fi
    else
	echo "Error: Unsupported distribution:" $1
	echo
	printUsage
	exit 3
    fi
    ARCH=$tmp_arch
    FDIST=$tmp_dist
}

checkArguments $@

echo "Downloading for for $DIST $PACK_ARCH"

NAME="$PACKAGE-$VERSION-$FDIST-$ARCH"

pwdir=`pwd`
tmpdir=`mktemp -d`
cd $tmpdir

prefix=http://download.opensuse.org/repositories/home:/martinsiggel/$DIST/$PACK_ARCH/

# get list of available files to download 
wget $prefix/
filelist=`cat index.html | grep  $PACK_TYPE | awk '{print $7}' |  cut -d'"' -f 2`

echo $filelist 

if [[ $PACK_TYPE == rpm ]]; then
  # select required files
  for file in $filelist; do
	#opencascade	
	if [[ $file == OCE*.rpm ]] && [[ $file != OCE-devel* ]]
	then
		bin_file_list+=($file)
	fi
	
	#ftgl
	if [[ $file == libftgl2*.rpm ]] && [[ $file != libftgl2-32bit*.rpm ]]
	then
		bin_file_list+=($file)
	fi

	#TIXI
	if [[ $file == libTIXI2*.rpm ]] 
	then
		bin_file_list+=($file)
	fi
	
	#TIGL
	if [[ $file == libTIGL2*.rpm ]] || [[ $file == tigl-*.rpm ]]
	then
		bin_file_list+=($file)
	fi
  done
elif [[ $PACK_TYPE == deb ]]; then
  # select required files
  for file in $filelist; do
	#opencascade	
	if [[ $file == liboce-*.deb ]] && [[ $file != liboce*dev* ]]
	then
		bin_file_list+=($file)
	fi

	#ftgl
	if [[ $file == libftgl2*.deb ]]
	then
		bin_file_list+=($file)
	fi

	#TIXI
	if [[ $file == libtixi2*.deb ]] 
	then
		bin_file_list+=($file)
	fi
	
	#TIGL
	if [[ $file == libtigl*.deb ]] || [[ $file == tigl-*.deb ]]
	then
		bin_file_list+=($file)
	fi
  done
else
    echo "Error: unknown package type"
    exit 4
fi


#download and extract files
for file in ${bin_file_list[@]}; do
	wget $prefix/$file
        if [[ $PACK_TYPE == rpm ]]; then
	    rpm2cpio $file | cpio -idmv
	elif [[ $PACK_TYPE == deb ]]; then
	    ar x $file
	    tar -zxvf data.tar.gz
	else
	    echo "Unknown package type $PACK_TYPE"
	    exit 5
	fi
done

mv usr/ $NAME
cd $NAME

#create start script for tiglviewer
echo "#!/bin/bash" > tiglviewer.sh
echo 'CURDIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"' >> tiglviewer.sh
echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CURDIR/'$LIBDIR/ >> tiglviewer.sh
if [[ $PACK_TYPE == deb ]]; then
    echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$CURDIR/'$LIBDIR/$ARCH-linux-gnu/ >> tiglviewer.sh   
fi
echo 'export CSF_GraphicShr=$CURDIR/'$LIBDIR/libTKOpenGl.so.5 >> tiglviewer.sh
echo '$CURDIR/bin/TIGLViewer' >> tiglviewer.sh
chmod +x tiglviewer.sh

cd ..


echo
echo "create package $NAME.tar.gz"
tar -czf $pwdir/$NAME.tar.gz $NAME

rm -rf $tmpdir

echo "Package generation done..." 
