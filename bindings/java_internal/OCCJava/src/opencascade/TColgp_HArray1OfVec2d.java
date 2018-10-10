package opencascade;

public class TColgp_HArray1OfVec2d extends Standard_Transient {
  TColgp_HArray1OfVec2d(long cPtr, boolean cMemoryOwn){super(cPtr, cMemoryOwn);}
   
  public synchronized void disposeUnused() {}

  public TColgp_HArray1OfVec2d(int theLower, int theUpper,  gp_Vec2d  theValue) {
    this(OCCwrapJavaJNI.new_TColgp_HArray1OfVec2d__SWIG_0(theLower, theUpper, gp_Vec2d.getCPtr(theValue), theValue), true);
  }

  public TColgp_HArray1OfVec2d(int theLower, int theUpper) {
    this(OCCwrapJavaJNI.new_TColgp_HArray1OfVec2d__SWIG_1(theLower, theUpper), true);
  }

  public TColgp_HArray1OfVec2d( TColgp_Array1OfVec2d  theOther) {
    this(OCCwrapJavaJNI.new_TColgp_HArray1OfVec2d__SWIG_2(TColgp_Array1OfVec2d.getCPtr(theOther), theOther), true);
  }

  public  TColgp_Array1OfVec2d  Array1() {
    TColgp_Array1OfVec2d ret = new TColgp_Array1OfVec2d(OCCwrapJavaJNI.TColgp_HArray1OfVec2d_Array1(swigCPtr, this), false, this);
    return ret;
  }

  public  TColgp_Array1OfVec2d  ChangeArray1() {
    TColgp_Array1OfVec2d ret = new TColgp_Array1OfVec2d(OCCwrapJavaJNI.TColgp_HArray1OfVec2d_ChangeArray1(swigCPtr, this), false, this);
    return ret;
  }

  public int Size() {
    return OCCwrapJavaJNI.TColgp_HArray1OfVec2d_Size(swigCPtr, this);
  }

  public int Length() {
    return OCCwrapJavaJNI.TColgp_HArray1OfVec2d_Length(swigCPtr, this);
  }

  public int Lower() {
    return OCCwrapJavaJNI.TColgp_HArray1OfVec2d_Lower(swigCPtr, this);
  }

  public int Upper() {
    return OCCwrapJavaJNI.TColgp_HArray1OfVec2d_Upper(swigCPtr, this);
  }

  public  gp_Vec2d  Value(int theIndex) {
    gp_Vec2d ret = new gp_Vec2d(OCCwrapJavaJNI.TColgp_HArray1OfVec2d_Value(swigCPtr, this, theIndex), true);
    return ret;
  }

  public gp_Vec2d ChangeValue(int theIndex) {
    gp_Vec2d ret = new gp_Vec2d(OCCwrapJavaJNI.TColgp_HArray1OfVec2d_ChangeValue(swigCPtr, this, theIndex), false, this);
    return ret; //new gp_Vec2d.CRef (ret);
  }

  public void SetValue(int theIndex,  gp_Vec2d  theItem) {
    OCCwrapJavaJNI.TColgp_HArray1OfVec2d_SetValue(swigCPtr, this, theIndex, gp_Vec2d.getCPtr(theItem), theItem);
  }

  public static  TColgp_HArray1OfVec2d  DownCast( Standard_Transient  T) {
    return new TColgp_HArray1OfVec2d ( OCCwrapJavaJNI.TColgp_HArray1OfVec2d_DownCast( Standard_Transient.getCPtr(T) , T), true );
  }

  public static  Standard_Type  TypeOf() {
    return new Standard_Type ( OCCwrapJavaJNI.TColgp_HArray1OfVec2d_TypeOf(), true );
  }

}
