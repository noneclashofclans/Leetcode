class Solution {
    public int romanToInt(String s) {
        int ans = 0;
        int n = s.length();
        int[] arr = new int[128];

        arr['I'] = 1;
        arr['V'] = 5;
        arr['X'] = 10;
        arr['L'] = 50;
        arr['C'] = 100;
        arr['D'] = 500;
        arr['M'] = 1000;

        for (int i = 0; i < n-1; i++){
            if (arr[s.charAt(i)] < arr[s.charAt(i+1)]){
                 ans -= arr[s.charAt(i)];
            }
            else ans += arr[s.charAt(i)];
        }
        return ans + arr[s.charAt(n - 1)];
    }
}