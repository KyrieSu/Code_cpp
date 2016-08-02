exports.getNowTime = function(){
    var date = new Date();
    var localdate = date.toLocaleDateString();
    var localtime = date.toLocaleTimeString();
    return (localdate + ' ' + localtime);
};
