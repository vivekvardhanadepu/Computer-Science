int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(x<0)
        x = (d + (x%d))%d;
    if(n==1)
        return x%d;
    if(n==0 && x==0)
        return 0;
    if(n==0)
        return 1;
    int mid = n/2;
    long long power = pow(x, mid, d);
    power = (power*power) % d;
    if(n%2==0){
        return power;
    }
    return (power * (x%d))%d;
}

// https://www.interviewbit.com/problems/implement-power-function/
