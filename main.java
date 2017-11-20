public class main 
{
    public static void main(String argv[]) 
    {
        System.loadLibrary("example"); // Attempts to load example.dll (on Windows) or libexample.so (on Linux)
        System.out.println(example.foo());
        SpaceSense_ fs = example.spacesense_new();
        SpaceSensePoint2f pt = example.spacesense_test_point(fs);
        if ( pt.getX() != 100 ) {
          System.exit(1);
        } 
        if ( pt.getY() != 200 ) {
          System.exit(1);
        } 
        
        example.spacesense_delete(fs);
        
        if ( example.foo() == 124 ) {
          System.exit(0);
        } 
        System.exit(1);
    }
}
