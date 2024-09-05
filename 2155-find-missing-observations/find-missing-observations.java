class Solution {
    public int[] missingRolls(int[] rolls, int mean, int n) {
        int m = rolls.length;
        int sum = mean * (n+m);

        for(int i=0;i<rolls.length;i++){
            sum -= rolls[i];
        }

        if(sum < n || sum > 6 * n){
            return new int[0];
        }

        int average = sum / n;
        int remainder = sum % n;
        int result[] = new int[n];

        for(int i=0;i<n;i++){
            result[i] = average;
            if(remainder > 0){
                result[i]++;
                remainder--;
            }
        }
        return result;
    }
}