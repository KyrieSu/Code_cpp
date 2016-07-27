/*
function add(x, y){
    return x + y;
}

var sub = function(x, y){
    return x - y;
}

function exec(func, x, y){
    return func(x, y);
}

var rst = add(1, 2);
var rst2 = exec(add, 1, 2);

var rst3 = exec(function(x, y){
    return x - y;
}, 1, 2);

console.log(rst);
console.log(rst2);
console.log(rst3);

(function(){
    var a = 10;
    var b = 5;
    console.log(a-b);
})();
*/

/*
var time = 0;
function count(){
    time++;
    return time;
}

console.log(count());
console.log(count());

var count2 = (function(){
    var time = 0;
    return function(){
        time++;
        return time;
    };
})();

console.log(count2());
console.log(count2());

function(){
    var a = 123;
    console.log(a);
}();
*/

var arr = [1, 2, 3, 4];
arr.forEach(function(e){
    console.log(e);
});

var arr2 = arr.map(function(e){
    return e * 2;
});

arr2.forEach(function(e){
    console.log(e);
});


