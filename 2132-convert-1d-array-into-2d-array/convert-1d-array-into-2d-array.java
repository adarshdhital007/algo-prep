class Solution {
    public int[][] construct2DArray(int[] original, int m, int n) {
        //convert from 1d to 2d 
        int totalElement = m * n;
        int [][] newArray = new int[m][n];

        if(original.length != totalElement){
            return new int[0][0];
        }

        for(int i=0;i<totalElement;i++){
            int row = i / n;
            int column = i % n;
            newArray[row][column] = original[i];
        }
        return newArray;
    }
}