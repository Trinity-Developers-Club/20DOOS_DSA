//import java.util.*;

public class tranposematrix {
 public static void main(String[] args) {
    System.out.println("Printing Matrix without transpose:");  
      int matrix[][]= {{1,2,3}, {4,5,6},{5,6,7}};
        int row=3, column=3;
        //print matrix
        for(int i=0;i<matrix.length;i++){
            for(int j=0;j<matrix[0].length;j++){
             System.out.print(matrix[i][j] + "  ");
            }
            System.out.println();
    }
        //transpose matrix
        int[][] transmatrix=new int[column][row];
        for(int i=0;i<row;i++){
            for(int j=0;j<column;j++){
                transmatrix[j][i]=matrix[i][j];
            }
        }
        System.out.println("Printing Matrix After Transpose:");  
        //print transpose matrix
            for(int i=0;i<matrix.length;i++){
                for(int j=0;j<matrix[0].length;j++){
                System.out.print(transmatrix[i][j] + "  ");
                } 
               System.out.println();
    }
}
}    



