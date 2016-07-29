var fs = require('fs');
var readline = require('readline');

var arr = ['test_hw2.ot','test_hw2_3a.ot','test_hw2_discard.ot','test_hw2_unsafe.ot']; // test data
var ans = [];

function test(filename,callback){
    var counter = 0;
    var lineReader = readline.createInterface({
        input: fs.createReadStream(filename)
    });
    lineReader.on('line', function(line){ // get line
        counter++;
    });
    lineReader.on('close',function(){ // get ^c || ^D
        console.log('EOF');
        ans.push(counter);
        console.log(ans)
    });
    if(ans.length===arr.length){
        callback('success');
    }
};

for(var i=0;i<arr.length;i++){
    test(arr[i],function(ans){
        console.log(ans);
    });
}
