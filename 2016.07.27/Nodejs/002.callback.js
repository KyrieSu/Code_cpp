var fs = require('fs');
/*

fs.readFile('data', function(err, data){
    console.log(data.toString());
});

setTimeout(function(){
    console.log('HI');
}, 3000);

console.log('ya');
*/

/*
// callback(msg)
function doSomething(callback){
    var random = Math.random();
    if(random > 0.5) callback('finish');
    else callback('error');
}

callback = function(msg){
    console.log(msg);
}

doSomething(function(msg){
    console.log(msg);
});
*/

/*

// callback(err, length)
function countLength(filename, callback){
    fs.readFile(filename, function(err, data){
        var length = data.toString().length;
        callback(err, length);
    });
}

countLength('data', function(err, length){
    console.log(length);
});

*/

// callback(errMessage)
function add123AtTail(filename, callback){
    fs.readFile(filename, function(err, data){
         if(err){
            callback(err);
            return;
         }
         var newData = data.toString() + '123';
         fs.writeFile(filename, newData, function(err){
            if(err){
                callback(err);
                return;
            }
            callback('success');
         });
    });
}

add123AtTail('data123', function(msg){
    console.log(msg);
});







