var RandomizedCollection = function() {
    this.nums = [];
    this.indices = new Map();
};

RandomizedCollection.prototype.insert = function(val) {
    const exists = this.indices.has(val) && this.indices.get(val).size > 0;
    if (!this.indices.has(val)) this.indices.set(val, new Set());
    this.indices.get(val).add(this.nums.length);
    this.nums.push(val);
    return !exists;
};

RandomizedCollection.prototype.remove = function(val) {
    if (!this.indices.has(val) || this.indices.get(val).size === 0) return false;

    const removeIdx = this.indices.get(val).values().next().value;
    const lastIdx = this.nums.length - 1;
    const lastVal = this.nums[lastIdx];

    this.nums[removeIdx] = lastVal;

    this.indices.get(val).delete(removeIdx);
    this.indices.get(lastVal).delete(lastIdx);
    if (removeIdx !== lastIdx) {
        if (!this.indices.has(lastVal)) this.indices.set(lastVal, new Set());
        this.indices.get(lastVal).add(removeIdx);
    }
    if (this.indices.has(val) && this.indices.get(val).size === 0) this.indices.delete(val);

    this.nums.pop();
    return true;
};

RandomizedCollection.prototype.getRandom = function() {
    return this.nums[Math.floor(Math.random() * this.nums.length)];
};
