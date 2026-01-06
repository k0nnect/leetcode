function exclusiveTime(n: number, logs: string[]): number[] {
    const result: number[] = new Array(n).fill(0);
    const stack: number[] = [];
    let prevTime = 0;

    for (const log of logs) {
        const [idStr, type, timeStr] = log.split(':');
        const id = parseInt(idStr);
        const timestamp = parseInt(timeStr);

        if (type === 'start') {
            if (stack.length > 0) {
                result[stack[stack.length - 1]] += timestamp - prevTime;
            }
            stack.push(id);
            prevTime = timestamp;
        } else {
            const topId = stack.pop()!;
            result[topId] += timestamp - prevTime + 1;
            prevTime = timestamp + 1;
        }
    }

    return result;
}