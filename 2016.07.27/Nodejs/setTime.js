var y = 1;

for(var i=1;i<=60;i++){
    setTimeout(function(){
        console.log(y++);
    },1000);
}
