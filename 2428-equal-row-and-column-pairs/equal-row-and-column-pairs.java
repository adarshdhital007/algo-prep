class Solution {
    public int equalPairs(int[][] grid) {
        int count = 0;
        int n = grid.length;
        Map<String, Integer> rowMap = new HashMap<>();

        for (int[] row : grid) {
            String rowKey = Arrays.toString(row);
            rowMap.put(rowKey, rowMap.getOrDefault(rowKey, 0) + 1);
        }

        for (int col = 0; col < n; col++) {
            int[] colArr = new int[n];
            for (int row = 0; row < n; row++) {
                colArr[row] = grid[row][col];
            }
            String colKey = Arrays.toString(colArr);
            count += rowMap.getOrDefault(colKey, 0);
        }

        return count;
    }
}