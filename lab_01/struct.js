const canvas = document.getElementById('cnv');
canvas.width = window.innerWidth * 0.75;
canvas.height = window.innerHeight;
const dx = canvas.width / 2;
const dy = canvas.height / 2;
const ctx = canvas.getContext('2d')

ctx.strokeStyle = "white"
//ctx.fillStyle = 'rgba(227, 104, 255, 0.3)';

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
    document.querySelector('.input-file-trigger').textContent = `upload a model`
    mainFunc('new model', ['cube'])
});
//createPrism
document.querySelector('#tr-prism').addEventListener('click', (e) => {
    document.querySelector('.input-file-trigger').textContent = `upload a model`
    mainFunc('new model', ['prism'])
});
//create piramid
document.querySelector('#piramid').addEventListener('click', (e) => {
    document.querySelector('.input-file-trigger').textContent = `upload a model`
    mainFunc('new model', ['piramid'])
});

mainFunc()