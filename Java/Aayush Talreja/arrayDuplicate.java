import java.util.LinkedHashSet;

public class arrayDuplicate {

    public static void removeDuplicates(int[] a) {
        LinkedHashSet<Integer> set = new LinkedHashSet<Integer>();
        for(int i=0; i<a.length; i++){
            set.add(a[i]);

            System.out.println(set);
        }
    }
    public static void main(String[] args) {
        int a [] = {1, 2, 5, 6, 2, 5, 9};

        removeDuplicates(a);
    }
}
