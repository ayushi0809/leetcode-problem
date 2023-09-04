/**
 * @param {number} rowsCount
 * @param {number} colsCount
 * @return {Array<Array<number>>}
 */
Array.prototype.snail = function(r, c) {
    if(r*c != this.length){
       return [];
    }
    let arr = [];
    for(let j=0;j<r;j++){
        arr.push([]);
    }
    // return arr;
    let row =0;
    let col =0;
    let i =0;
    while(i<this.length){
        // console.log(this[i]);
        while(row<r && i< this.length){
            arr[row].push(this[i]);
             console.log(this[i]);
            row++;
            i++;
        }
        row--;
        while(row>=0 && i< this.length){
            arr[row].push(this[i]);
            row--;
            i++;
        }
        row++;
        
    }
    
    return arr;
    // console.log(this.length);

}

/**
 * const arr = [1,2,3,4];
 * arr.snail(1,4); // [[1,2,3,4]]
 */