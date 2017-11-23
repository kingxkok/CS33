
var txt = ["a","b","c"];



for (var i = 0; i < 3; ++i ) {    

    setTimeout( (function(msg) { 

      return function() { console.log(msg); } 

    })(txt[i]), i*1000);        

}

