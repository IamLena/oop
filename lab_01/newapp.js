var Vertex = function(x, y, z) {
    this.x=parseFloat(x);
    this.y=parseFloat(y);
    this.z=parseFloat(z);
};
var A = new Vertex(10, 20, 0.5);

var Cube = function (center, size) {
    var d = size / 2;
    this.vertices = [
        new Vertex(center.x - d, center.y- d, center.z +d),
        new Vertex(center.x -d, center.y -d, center.z -d),
        new Vertex(center.x + d, center.y -d, center.z -d),
        new Vertex(center.x + d, center.y -d, center.z +d),
        new Vertex(center.x + d, center.y + d, center.z+ d),
        new Vertex(center.x + d, center.y + d, center.z - d),
        new Vertex(center.x - d, center.y + d, center.z - d),
        new Vertex(center.x - d, center.y + d, center.z + d)
    ];
    this.faces = [
        [this.vertices[0], this.vertices[1], this.vertices[2], this.vertices[3]],
        [this.vertices[3], this.vertices[2], this.vertices[5], this.vertices[4]],
        [this.vertices[4], this.vertices[5], this.vertices[6], this.vertices[7]],
        [this.vertices[7], this.vertices[6], this.vertices[1], this.vertices[0]],
        [this.vertices[7], this.vertices[0], this.vertices[3], this.vertices[4]],
        [this.vertices[1], this.vertices[6], this.vertices[5], this.vertices[2]]
    ];
    this.edges = [
        [this.vertices[0], this.vertices[1]],
        [this.vertices[1], this.vertices[2]],
        [this.vertices[2], this.vertices[3]],
        [this.vertices[3], this.vertices[0]],

        [this.vertices[4], this.vertices[5]],
        [this.vertices[5], this.vertices[6]],
        [this.vertices[6], this.vertices[7]],
        [this.vertices[7], this.vertices[4]],

        [this.vertices[3], this.vertices[4]],
        [this.vertices[2], this.vertices[5]],
        [this.vertices[1], this.vertices[6]],
        [this.vertices[0], this.vertices[7]]
    ]
};

function renderModel(model, ctx, dx, dy) {
    ctx.clearRect(0, 0, 2*dx, 2*dy);
    for (var j = 0, n_faces = model.faces.length; j < n_faces; ++j) {        
        var face = model.faces[j];
        var P = project(face[0]);
        ctx.beginPath();
        ctx.moveTo(P.x + dx, -P.y + dy);
        for (var k = 1, n_vertices = face.length; k < n_vertices; ++k) {
            P = project(face[k]);
            ctx.lineTo(P.x + dx, -P.y + dy);
        }
        ctx.closePath();
        ctx.stroke();
        //ctx.fill();
    }
}

function render(objects, ctx, dx, dy) {
    ctx.clearRect(0, 0, 2*dx, 2*dy);
    for (var i = 0, n_obj = objects.length; i < n_obj; ++i) {
        var face = objects[i].faces[0];
        var P = project(face[0]);
        ctx.beginPath();
        ctx.moveTo(P.x + dx, -P.y + dy);
        for (var k = 1, n_vertices = face.length; k < n_vertices; ++k) {
            P = project(face[k]);
            ctx.lineTo(P.x + dx, -P.y + dy);
        }
        ctx.closePath();
        ctx.stroke();
        ctx.fillStyle = 'red'
        ctx.fill();

        for (var j = 1, n_faces = objects[i].faces.length; j < n_faces; ++j) {        
            var face = objects[i].faces[j];
            var P = project(face[0]);
            ctx.beginPath();
            ctx.moveTo(P.x + dx, -P.y + dy);
            for (var k = 1, n_vertices = face.length; k < n_vertices; ++k) {
                P = project(face[k]);
                ctx.lineTo(P.x + dx, -P.y + dy);
            }
            ctx.closePath();
            ctx.stroke();
            //ctx.fill();
        }
    }
}

var Vertex2D = function(x, y) {
    this.x = parseFloat(x);
    this.y = parseFloat(y);
};
function project(M) {
    return new Vertex2D(M.x, M.z);
};

mainFunc = function() {
    // Fix the canvas width and height
    var canvas = document.getElementById('cnv');
    canvas.width = canvas.offsetWidth;
    canvas.height = canvas.offsetHeight;
    var dx = canvas.width / 2;
    var dy = canvas.height / 2;

    // Objects style
    var ctx = canvas.getContext('2d');
    ctx.strokeStyle = "white"

    // Create the cube
    var cube_center = new Vertex(0, 11*dy/10, 0);
    var cube = new Cube(cube_center, dy);
    var objects = [cube];
    //render(objects, ctx, dx, dy);
    renderModel(cube, ctx, dx, dy);

    // Events
    var mousedown = false;
    var mx = 0;
    var my = 0;

    canvas.addEventListener('mousedown', initMove);
    document.addEventListener('mousemove', move);
    document.addEventListener('mouseup', stopMove);

    document.addEventListener('keydown', key);

    function key(evt) {
        if (evt.keyCode == 38) {
            console.log('up')
            zoomMinus(cube, ctx, dx, dy)
        }
        if (evt.keyCode == 40) {
            console.log('down')
            zoomPlus(cube, ctx, dx, dy)
        }
        if (evt.keyCode == 37) {
            console.log('left')
            //rotateZLeft()
        }
        if (evt.keyCode == 39) {
            console.log('right')
            rotateZright(cube, cube_center)
        }
    }

    function zoomMinus(model, ctx, dx, dy) {
        model.vertices.forEach((vert) => {
            vert.x = vert.x * 0.9
            vert.y = vert.y * 0.9
            vert.z = vert.z * 0.9
        })
        renderModel(model, ctx, dx, dy);
    }

    function zoomPlus(model, ctx, dx, dy) {
        model.vertices.forEach((vert) => {
            vert.x = vert.x * 1.1
            vert.y = vert.y * 1.1
            vert.z = vert.z * 1.1
        })
        renderModel(model, ctx, dx, dy);
    }

    function rotateZright(model, center) {
        const alfa = 5 //degrees
        const cos = Math.cos(alfa * Math.PI/180)
        const sin = Math.sin(alfa * Math.PI/180)
        model.vertices.forEach((vert) => {
            let x = vert.x
            let y = vert.y
            vert.x = cos * (x - center.x) - sin * (y - center.y) + center.x
            vert.y = sin * (x - center.x) + cos * (y - center.y) + center.y
        })
        renderModel(model, ctx, dx, dy);
    }

    function rotateXY(M, center, theta, phi) {
        // Rotation matrix coefficients
        var ct = Math.cos(theta);
        var st = Math.sin(theta);
        var cp = Math.cos(phi);
        var sp = Math.sin(phi);

        // Rotation
        var x = M.x - center.x;
        var y = M.y - center.y;
        var z = M.z - center.z;

        M.x = ct * x - st * cp * y + st * sp * z + center.x;
        M.y = st * x + ct * cp * y - ct * sp * z + center.y;
        M.z = sp * y + cp * z + center.z;
    }
   
    function initMove(evt) {
        mousedown = true;
        mx = evt.clientX;
        my = evt.clientY;
    }

    function move(evt) {
        if (mousedown) {
            // speed of rotating
            // connection between angle and movement of the mouse
            var theta = (evt.clientX - mx) * Math.PI / 360;
            var phi = (evt.clientY - my) * Math.PI / 360;

            for (var i = 0; i < 8; ++i) {
                rotateXY(cube.vertices[i], cube_center, theta, phi);
            }

            mx = evt.clientX;
            my = evt.clientY;

            //render(objects, ctx, dx, dy);
            renderModel(cube, ctx, dx, dy);
        }
    }

    function stopMove() {
        mousedown = false;
    }
};

mainFunc();