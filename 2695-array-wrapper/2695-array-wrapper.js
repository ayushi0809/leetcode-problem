/**
 * @param {number[]} nums
 */
var ArrayWrapper = function(nums) {
    this.nums = nums
    
    
    
};

ArrayWrapper.prototype.valueOf = function() {
    let sum =0;
    for(let s of this.nums){
        sum = sum + s;
    }
    return sum;
}

ArrayWrapper.prototype.toString = function() {
    if(this.nums.length === 0){
        return "[]"
    }
    let str = "[";
    for(let i =0 ;i<this.nums.length-1; i++){
        str = str + this.nums[i] + ',';
    }
    str = str + this.nums[this.nums.length-1] + ']'
    return str;
    
}

/**
 * const obj1 = new ArrayWrapper([1,2]);
 * const obj2 = new ArrayWrapper([3,4]);
 * obj1 + obj2; // 10
 * String(obj1); // "[1,2]"
 * String(obj2); // "[3,4]"
 */