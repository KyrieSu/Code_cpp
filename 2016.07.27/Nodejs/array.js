var fs = require('fs');
var readline = require('readline');

var arr = ['test_hw2.ot','test_hw2_3a.ot','test_hw2_discard.ot','test_hw2_unsafe.ot']; // test data

function countLine(filename,i,callback){
    var counter = 0;
    var lineReader = readline.createInterface({
        input: fs.createReadStream(filename)
    });
    lineReader.on('line', function(line){ // get line
        counter++;
    });
    lineReader.on('close',function(){ // get ^c || ^D
        //console.log('EOF');
        callback(i,counter);
    });
};

function finialcheck(ans){
    if(ans.length!=arr.length)
        return false;
    for(var i=0;i<ans.length;i++){
        if(ans[i]==undefined)
            return false;
    }
    return true;
}

function finish(callback){
    var ans = [];
    for(var i=0;i<arr.length;i++){
        countLine(arr[i],i,function(index,line){
            ans[index] = line;
            if(finialcheck(ans))
                callback(ans);
        });
    }
}

finish(function(ans){
    console.log(ans);
});
