const addon = require('./build/Release/addon');

function jsum() {
    let a = 3, b = 200;
    for (let i = 0; i < 10000; i++) a += b; 
    return a;
}

console.time('c++');
addon.sum();
console.timeEnd('c++');

console.time('js');
jsum();
console.timeEnd('js');