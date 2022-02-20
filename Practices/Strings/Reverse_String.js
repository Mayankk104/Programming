const arr = ['Komal', 'Mayank', 'I', 'Am', 'Lvu', 'Haha'];

arr.forEach(str => {
    console.log(reverse(str));
});

function reverse(str) {
    let l = str.length;
    for (let i = 0; i < Math.floor(l / 2); i++)
        str =
            str.substring(0, i) +
            str.substring(l - 1 - i, l - i) +
            str.substring(i + 1, l - 1 - i) +
            str.substring(i, i + 1) +
            str.substring(l - i);
    return str;
}

//TODO: Add attach this method to prototype
