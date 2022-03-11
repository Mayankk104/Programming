console.clear();

// TODO: Complete insertion sort.
function Insertion(arr: number[]) {
    for (let i = 1; i < arr.length; i++) {
        for (let j = i - 1; j >= 0; j--)
            if (arr[i] < arr[j]) {
                arr.splice(j - 1, 0, arr[i]);
                arr.splice(i + 1, 1);
                break;
            }
    }

    return arr;
}

console.log(Insertion([1, 0]));
