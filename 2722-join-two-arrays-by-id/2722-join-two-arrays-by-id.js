/**
 * @param {Array} arr1
 * @param {Array} arr2
 * @return {Array}
 */
var join = function(arr1, arr2) {
    var mp = new Map();
    arr1.map((arr) => mp.set(arr.id, arr));
    arr2.map((arr) => {
        if(mp.has(arr.id)){
            var obj = mp.get(arr.id);
            console.log(obj);
            var nobj = {};
            
            for(const k of Object.keys(obj)){
                if(!arr.hasOwnProperty(k)){
                    arr[k] = obj[k];
                }
               
            }
            
        }
      
            mp.set(arr.id,arr);
        
    });
    var ans = [];
    console.log(mp);
    mp.forEach((value,key) => {
        console.log(key);
        ans.push(value);
    });
    
    ans.sort(function(a, b) {
  var keyA = new Date(a.id),
    keyB = new Date(b.id);
  // Compare the 2 dates
  if (keyA < keyB) return -1;
  if (keyA > keyB) return 1;
  return 0;
});
    return ans;
    
};