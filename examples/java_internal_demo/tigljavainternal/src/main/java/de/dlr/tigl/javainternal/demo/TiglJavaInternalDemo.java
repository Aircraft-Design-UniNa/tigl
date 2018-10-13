package de.dlr.tigl.javainternal.demo;

import opencascade.Geom_Circle;
import opencascade.Geom_Curve;
import opencascade.gp_Ax2;
import opencascade.gp_Dir;
import opencascade.gp_Pnt;

public class TiglJavaInternalDemo {

	public static void main(String[] args) {
		
		System.out.println("Hello Tigl-Java-Internal bindings!");
		
		gp_Pnt p = new gp_Pnt(1, 2, 3);
		gp_Ax2 ax = new gp_Ax2(p, new gp_Dir(1, 0, 0));
        Geom_Curve c = new Geom_Circle(ax, 10.8);

        System.out.println("Radius: " + ((Geom_Circle)c).Radius());

	}
}