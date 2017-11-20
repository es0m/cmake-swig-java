
public class main 
{

    public static boolean testArrays(SpaceSense_ ss)
    {
      int N = example.SPACESENSE_MAX_STATES; // should be 
      SpaceSenseStateArray states = new SpaceSenseStateArray(N);
      int res = example.spacesense_frobnicate(ss, N, states.cast());//, n_frobnications);
      for ( int i=0; i<res; ++i ) {
        SpaceSenseState state = states.getitem(i);
        if ( state.getN_points() != i ) {
          return false;
        }
        System.out.println("Java state: " + i);
        for ( int j=0; j<state.getN_points(); ++j ) {
          SpaceSensePoint2f p = state.getPoints();
        }
      }
      return res == N;
    }

    public static void main(String argv[]) 
    {
        System.loadLibrary("example"); // Attempts to load example.dll (on Windows) or libexample.so (on Linux)
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
        
        if ( example.foo() == 124 ) {
          System.exit(0);
        } 
        System.exit(1);
    }
}
