var canvas = document.getElementById('cnv');
canvas.width = window.innerWidth * 0.75;
canvas.height = window.innerHeight;
var dx = canvas.width / 2;
var dy = canvas.height / 2;
const ctx = canvas.getContext('2d')

ctx.strokeStyle = "white"
ctx.fillStyle = 'rgba(0, 200, 100, 0.3)';

let model_center = new Vertex(0, 0, 0)
let model = new Cube(model_center, dy)
let mousedown = false
let mx, my

canvas.addEventListener('mousedown', (e) => {
    mainFunc('initMove', [e.clientX, e.clientY])
});
document.addEventListener('mousemove', (e) => {
    mainFunc('move', [e.clientX, e.clientY])
});
document.addEventListener('mouseup', (e) => {
    mainFunc('stopMove')
});
document.addEventListener('keydown', (e) => {
    mainFunc('key', [e.code])
});
//createCube
document.querySelector('#cube').addEventListener('click', (e) => {
    mainFunc()
});
//createPrism
document.querySelector('#tr-prism').addEventListener('click', (e) => {
    mainFunc()
});
const file = document.querySelector('#my-file')
console.log(file.onchange)

mainFunc()