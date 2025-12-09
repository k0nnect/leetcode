var arraySign = function(nums) {
    let negatives = 0;

    for (let n of nums) {
        if (n === 0) return 0;
        if (n < 0) negatives++;
    }

    return negatives % 2 === 0 ? 1 : -1;
};