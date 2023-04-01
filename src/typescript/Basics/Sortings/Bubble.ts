function bubble(arr: number[]): number[] {
    let swap: boolean;
    let l = arr.length - 1;

    for (let i = 0; i < l; i++) {
        swap = false;
        for (let j = 0; j < l - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap = true;
                [arr[j], arr[j + 1]] = [arr[j + 1], arr[j]];
            }
        }
        if (!swap) break;
    }

    return arr;
}

console.log(bubble([1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 300, 64, 110, 220]));

// Space Complexity
// O(1)

// Time Complexity
// Best   O(n)
// Avg    O(n²)
// Worst  O(n²)
