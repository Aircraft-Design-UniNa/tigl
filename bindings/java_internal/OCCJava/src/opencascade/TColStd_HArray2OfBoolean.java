package opencascade;

public class TColStd_HArray2OfBoolean extends Standard_Transient {
  TColStd_HArray2OfBoolean(long cPtr, boolean cMemoryOwn){super(cPtr, cMemoryOwn);}
   
  public synchronized void disposeUnused() {}

  public TColStd_HArray2OfBoolean(int theRowLow, int theRowUpp, int theColLow, int theColUpp,  long  theValue) {
    this(OCCwrapJavaJNI.new_TColStd_HArray2OfBoolean__SWIG_0(theRowLow, theRowUpp, theColLow, theColUpp,  theValue ), true);
  }

  public TColStd_HArray2OfBoolean(int theRowLow, int theRowUpp, int theColLow, int theColUpp) {
    this(OCCwrapJavaJNI.new_TColStd_HArray2OfBoolean__SWIG_1(theRowLow, theRowUpp, theColLow, theColUpp), true);
  }

  public TColStd_HArray2OfBoolean( TColStd_Array2OfBoolean  theOther) {
    this(OCCwrapJavaJNI.new_TColStd_HArray2OfBoolean__SWIG_2(TColStd_Array2OfBoolean.getCPtr(theOther), theOther), true);
  }

  public  TColStd_Array2OfBoolean  Array2() {
    TColStd_Array2OfBoolean ret = new TColStd_Array2OfBoolean(OCCwrapJavaJNI.TColStd_HArray2OfBoolean_Array2(swigCPtr, this), false, this);
    return ret;
  }

  public  TColStd_Array2OfBoolean  ChangeArray2() {
    TColStd_Array2OfBoolean ret = new TColStd_Array2OfBoolean(OCCwrapJavaJNI.TColStd_HArray2OfBoolean_ChangeArray2(swigCPtr, this), false, this);
    return ret;
  }

  public int Size() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_Size(swigCPtr, this);
  }

  public int Length() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_Length(swigCPtr, this);
  }

  public int RowLength() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_RowLength(swigCPtr, this);
  }

  public int ColLength() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_ColLength(swigCPtr, this);
  }

  public int LowerRow() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_LowerRow(swigCPtr, this);
  }

  public int UpperRow() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_UpperRow(swigCPtr, this);
  }

  public int LowerCol() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_LowerCol(swigCPtr, this);
  }

  public int UpperCol() {
    return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_UpperCol(swigCPtr, this);
  }

  public  long  Value(int theRow, int theCol) { return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_Value(swigCPtr, this, theRow, theCol); }

  public long[] ChangeValue(int theRow, int theCol) {return OCCwrapJavaJNI.TColStd_HArray2OfBoolean_ChangeValue(swigCPtr, this, theRow, theCol);}

  public void SetValue(int theRow, int theCol,  long  theItem) {
    OCCwrapJavaJNI.TColStd_HArray2OfBoolean_SetValue(swigCPtr, this, theRow, theCol,  theItem );
  }

  public static  TColStd_HArray2OfBoolean  DownCast( Standard_Transient  T) {
    return new TColStd_HArray2OfBoolean ( OCCwrapJavaJNI.TColStd_HArray2OfBoolean_DownCast( Standard_Transient.getCPtr(T) , T), true );
  }

  public static  Standard_Type  TypeOf() {
    return new Standard_Type ( OCCwrapJavaJNI.TColStd_HArray2OfBoolean_TypeOf(), true );
  }

}
