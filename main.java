public class main 
{
    public static void main(String argv[]) 
    {
        System.loadLibrary("example"); // Attempts to load example.dll (on Windows) or libexample.so (on Linux)
        System.out.println(example.foo());
        FaceSense_ fs = example.facesense_new();
        FaceSensePoint2f pt = example.facesense_test_point(fs);
        if ( pt.getX() != 100 ) {
          System.exit(1);
        } 
        if ( pt.getY() != 200 ) {
          System.exit(1);
        } 
        
        example.facesense_delete(fs);
        
        if ( example.foo() == 124 ) {
          System.exit(0);
        } 
        System.exit(1);
    }
}
