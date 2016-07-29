var fs = require('fs');
var readline = require('readline');


//callback(err,line)
function countLine(filename,callback){
    var counter = 0;
    var lineReader = readline.createInterface({
        input: fs.createReadStream(filename)
    });
    lineReader.on('line', function(line){ // get line
        counter++;
    });
    lineReader.on('close',function(){ // get ^c || ^D
        console.log('EOF');
        callback(counter);
    });
};

countLine('data',function(line){
    console.log(line);
});
