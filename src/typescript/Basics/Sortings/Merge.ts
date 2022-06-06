console.clear();
function merge(arr: number[]): number[] {
    if (arr.length <= 1)
        return arr;

    let arr2 = arr.splice(0, Math.floor((arr.length) / 2));
    arr2 = merge(arr2);
    arr = merge(arr);

    return merge_sorted_arraies(arr2, arr);
}

function merge_sorted_arraies(arr1: number[], arr2: number[]) {
    let i = 0, j = 0;
    let arr: number[] = [];

    while (i !== arr1.length || j !== arr2.length) {
        if ((arr1[i] < arr2[j] && arr1[i] !== undefined) || arr2[j] === undefined) {
            arr.push(arr1[i]);
            i++;
        } else {
            arr.push(arr2[j]);
            j++;
        }
    }
    return arr;
}

console.log(merge([-2, 0, -1]));