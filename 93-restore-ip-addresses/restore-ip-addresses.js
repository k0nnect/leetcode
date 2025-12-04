var restoreIpAddresses = function(s) {
    const res = [];

    function backtrack(start, parts, path) {
   
        if (parts === 4) {
            if (start === s.length) {
                res.push(path.join('.'));
            }
            return;
        }

        for (let len = 1; len <= 3; len++) {
            if (start + len > s.length) break;

            const segment = s.substring(start, start + len);
            const val = Number(segment);

            if (val > 255 || (segment.length > 1 && segment[0] === '0')) continue;

            path.push(segment);
            backtrack(start + len, parts + 1, path);
            path.pop();
        }
    }

    backtrack(0, 0, []);
    return res;
};
