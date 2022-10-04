// Find maximum and minimum in an array

import java.util.Scanner;

public class Max_Min {
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        System.out.print("Enter a size:");
        int size = input.nextInt();
        System.out.print("Enter array:");
        int numbers[] = new int[size];
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;

        // Taking array as input
        for (int i = 0; i < size; i++) {
            numbers[i] = input.nextInt();
        }

        // Logic to find minimum and maximum
        for (int i = 0; i < numbers.length; i++) {
            if (numbers[i] < min) {
                min = numbers[i];
            }
            if (numbers[i] > max) {
                max = numbers[i];
            }
        }
        System.out.println("Min number is:" + min);
        System.out.println("Max number is:" + max);
    }
}
