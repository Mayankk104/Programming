package array;

public class SubarrayOR {
    private static final int MOD = (int)1e9+7;

    public static int solve(int[] arr) {
        int size = arr.length;
        long result = 0, combinations = (long)size * (size + 1)/2;

        for(int i=0; i<27; i++) { // 2^27 =  134217728 ~ (1 * 10^8)
            long consecutive_zeros = 0, count_subarray_with_zeros = 0;

            for(int num: arr) {
                if((num & (1<<i)) == 0) {
                    consecutive_zeros++;
                } else {
                    count_subarray_with_zeros += (consecutive_zeros * (consecutive_zeros+1))/ 2;
                    consecutive_zeros = 0;
                }
            }
            count_subarray_with_zeros += (consecutive_zeros * (consecutive_zeros+1))/ 2;
            result += (combinations - count_subarray_with_zeros) * (1<<i);
        }
        return (int)(result % MOD);
    }

    public static void main(String[] args) {
        int[] input = new int[] {1,2,3,4,5}; // constrains 1 <= input.length <= 10^5, 1<=input[i]<=10^8;
        int result = solve(input);
        System.out.println(result);
    }
}
