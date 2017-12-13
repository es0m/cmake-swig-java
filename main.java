
public class main 
{
    public static boolean compareStates(SpaceSenseStateArray states, int N, int res)
    {
      for ( int i=0; i<res; ++i ) {
        SpaceSenseState state = states.getitem(i);
        if ( state.getN_points() != i ) {
          return false;
        }
        SpaceSensePoint2fArray pts = SpaceSensePoint2fArray.frompointer(state.getPoints());
        for ( int j=0; j<state.getN_points(); ++j ) {
          SpaceSensePoint2f pt = pts.getitem(j);
          if ( pt.getX() !=j ) {
            return false;
          }
          if ( pt.getY() !=j ) {
            return false;
          }
        }
        System.out.println("Java state: " + i + " ok!");
      }
      return res == N;
    }

    public static boolean testFrobnicate(SpaceSense_ ss, SpaceSenseStateArray states, int N)
    {
      int res = example.spacesense_frobnicate(ss, N, states.cast());
      return compareStates(states, N, res);
    }
    public static boolean testDiscombobulate(SpaceSense_ ss, SpaceSenseStateArray states, int N)
    {
      int[] out = {0}; 
      int res = example.spacesense_discombobulate(ss, N, states.cast(), out);
      boolean success = out[0] == N;
      return compareStates(states, N, res) && success;
    }
    
    public static boolean testArrays(SpaceSense_ ss)
    {
      int N = example.SPACESENSE_MAX_STATES; 
      SpaceSenseStateArray states = new SpaceSenseStateArray(N);
      boolean frob_ok = testFrobnicate(ss, states, N);
      boolean xoox_ok = testDiscombobulate(ss, states, N);
      return frob_ok && xoox_ok;
    }
    
    public static boolean testImage()
    {
      long val = 10000; 
      int len = 10;
      SpaceSenseImage image = example.spacesense_image_new();

      example.spacesense_image_from_buffer(image, val, len);
      
      example.spacesense_image_delete(image);
      return true;
    }
    
    public static boolean testConstChar()
    {
      long val = 10000; 
      SpaceSense_ ss = example.spacesense_new();
      String s = example.spacesense_version(ss);
      example.spacesense_delete(ss);
      System.out.println("Version: " + s);
      return s.equals("Version 1");
    }
    
    public static void main(String argv[]) 
    {
        System.loadLibrary("example"); // Attempts to load example.dll (on Windows) or libexample.so (on Linux)
        if ( !testConstChar() ) {
            System.exit(1);
        }
        System.out.println(example.foo());
        SpaceSense_ ss = example.spacesense_new();
        SpaceSensePoint2f pt = example.spacesense_test_point(ss);
        if ( pt.getX() != 100 ) {
          System.exit(1);
        } 
        if ( pt.getY() != 200 ) {
          System.exit(1);
        } 
        boolean success = testArrays(ss);
        if ( !success ) {
          System.exit(1);
        }
        example.spacesense_delete(ss);
        if ( example.foo() != 124 ) {
          System.exit(1);
        } 
        if ( !testImage() ) {
          System.exit(1);
        }
        System.exit(0);
    }
}
