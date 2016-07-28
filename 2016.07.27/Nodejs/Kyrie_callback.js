var fs = require('fs');
var readline = require('readline');

//callback(err,line)
function countLine(filename,callback){
    var lineReader = readline.createInterface({
        input: fs.createReadStream(filename)
    });
    lineReader.on('line', function(line){
        callback(line);
    });
};

countLine('data',function(line){
    console.log(line);
});
