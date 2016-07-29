var fs = require('fs');
var readline = require('readline');

var counter = 0;
//callback(err,line)
function countLine(filename,callback){
    var lineReader = readline.createInterface({
        input: fs.createReadStream(filename)
    });
    lineReader.on('line', function(line){
        counter++;
    });
    callback(counter);
};

countLine('data',function(line){
    console.log(line);
});
