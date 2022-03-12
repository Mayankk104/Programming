let arr: number[] = [];
let randomNumber: number;

function Insertion(arr: number[]) {
    for (let i = 1; i < arr.length; i++)
        for (let j = i - 1; j >= -1; j--)
            if (arr[i] > arr[j] || j === -1) {
                arr.splice(j + 1, 0, arr[i]);
                arr.splice(i + 1, 1);
                break;
            }


    return arr;
}

for (let i = 0; i < 100; i++) {
    randomNumber = Math.floor(Math.random() * 200);
    arr.push(randomNumber);
}

console.log(arr);
console.log(Insertion(arr));


// Space Complexity
    // O(1)

// Time Complexity
    // Best   O(n)
    // Avg    O(n²)
    // Worst  O(n²)