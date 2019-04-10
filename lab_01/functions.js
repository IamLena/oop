var Vertex = function(x, y, z) {
    console.log(x, y, z)
    this.x=parseFloat(x);
    this.y=parseFloat(y);
    this.z=parseFloat(z);
    console.log(this.x, this.y, this.z)
};

var Cube = function (center, size) {
    this.center = center
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
};

var Prisma = function (center, size) {
    this.center = center
    var d = size / 2;
    let x = center.x
    let y = center.y
    let z = center.z
    let cos = Math.cos(Math.PI / 3)
    let sin = Math.sin(Math.PI / 3)
    this.vertices = [
        new Vertex(x - d, y - d, z +d),//0
        new Vertex(x + d, y -d, z + d),//1
        new Vertex(x, y + d, z + d),//2
        new Vertex(x - d, y - d, z - d),//3
        new Vertex(x + d, y -d, z - d),//4
        new Vertex(x, y + d, z - d)//5
    ];
    this.faces = [
        [this.vertices[0], this.vertices[1], this.vertices[2]],
        [this.vertices[3], this.vertices[4], this.vertices[5]],
        [this.vertices[0], this.vertices[1], this.vertices[4], this.vertices[3]],
        [this.vertices[1], this.vertices[2], this.vertices[5], this.vertices[4]],
        [this.vertices[0], this.vertices[2], this.vertices[5], this.vertices[3]]
    ];
}

var SomeModel = function (center, vertices, faces) {
    this.center = center
    this.vertices = vertices
    this.faces = faces
}

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

function project(M) {
    return {x: M.x, y: M.z}
};

function mainFunc(command, argumentsArray) {
    if (command === 'initMove') {
        mousedown = true;
        mx = argumentsArray[0]
        my = argumentsArray[1]
    }
    else if (command === 'move') {
        if (mousedown) {
            //mouse coordinates
            x = argumentsArray[0]
            y = argumentsArray[1]

            // speed of rotating
            // connection between angle and movement of the mouse
            const theta = (x - mx) * Math.PI / 360;
            const phi = (y - my) * Math.PI / 360;

            for (let i = 0, len = model.vertices.length; i < len; ++i) {
                rotateXZ(model.vertices[i], model.center, theta, phi);
            }

            mx = x;
            my = y;
            renderModel(model, ctx, dx, dy);
        }
    }
    else if (command === 'stopMove') {
        mousedown = false;
    }
    else if (command === 'key') {
        if (argumentsArray[0] == "ArrowUp") {
            zoomMinus(model, ctx, dx, dy)
        }
        if (argumentsArray[0] == "ArrowDown") {
            zoomPlus(model, ctx, dx, dy)
        }
        if (argumentsArray[0] == "ArrowLeft") {
            rotateYleft(model, ctx, dx, dy)
        }
        if (argumentsArray[0] == "ArrowRight") {
            rotateYright(model, ctx, dx, dy)
        }
    }
    else if(command === 'file') {
        console.log('main')
        model = argumentsArray[0]
        renderModel(model, ctx, dy, dx)
    }
    else if (command === 'new model') {
        model_center = new Vertex(0, 0, 0);
        if (argumentsArray[0] === 'cube') {
            model = new Cube(model_center, dy)
        }
        else if (argumentsArray[0] === 'prism') {
            model = new Prisma(model_center, dy)
        }
        renderModel(model, ctx, dx, dy)
    }
    else {
        renderModel(model, ctx, dx, dy)
    }
}

function rotateXZ(model, center, theta, phi) {
    // Rotation matrix coefficients
    var ct = Math.cos(theta);
    var st = Math.sin(theta);

    var cp = Math.cos(phi);
    var sp = Math.sin(phi);

    // Rotation
    var x = model.x - center.x;
    var y = model.y - center.y;
    var z = model.z - center.z;

    model.x = ct * x - st * cp * y + st * sp * z + center.x;
    model.y = st * x + ct * cp * y - ct * sp * z + center.y;
    model.z = sp * y + cp * z + center.z;
}
function zoomMinus(model, ctx, dx, dy) {
    model.center.x *= 0.9
    model.center.y *= 0.9
    model.center.z *= 0.9
    model.vertices.forEach((vert) => {
        vert.x = vert.x * 0.9
        vert.y = vert.y * 0.9
        vert.z = vert.z * 0.9
    })
    renderModel(model, ctx, dx, dy);
}
function zoomPlus(model, ctx, dx, dy) {
    model.center.x *= 1.1
    model.center.y *= 1.1
    model.center.z *= 1.1
    model.vertices.forEach((vert) => {
        vert.x = vert.x * 1.1
        vert.y = vert.y * 1.1
        vert.z = vert.z * 1.1
    })
    renderModel(model, ctx, dx, dy);
}
function rotateYright(model, ctx, dx, dy) {
    center = model.center
    const alfa = -5 //degrees
    const cos = Math.cos(alfa * Math.PI/180)
    const sin = Math.sin(alfa * Math.PI/180)
    model.vertices.forEach((vert) => {
        let x = vert.x - center.x;
        let z = vert.z - center.z;
        vert.x = cos * (x - center.x) - sin * (z - center.z) + center.x
        vert.z = sin * (x - center.x) + cos * (z - center.z) + center.z
    })
    renderModel(model, ctx, dx, dy);
}
function rotateYleft(model, ctx, dx, dy) {
    center = model.center
    const alfa = 5 //degrees
    const cos = Math.cos(alfa * Math.PI/180)
    const sin = Math.sin(alfa * Math.PI/180)
    model.vertices.forEach((vert) => {
        let x = vert.x - center.x;
        let z = vert.z - center.z;
        vert.x = cos * (x - center.x) - sin * (z - center.z) + center.x
        vert.z = sin * (x - center.x) + cos * (z - center.z) + center.z
    })
    renderModel(model, ctx, dx, dy);
}
function parseFile(file) {
    if (file) {
        document.querySelector('.input-file-trigger').textContent = `${file.name}`
        if (window.FileReader) {
            const reader = new FileReader()
            reader.readAsText(file)
            reader.onloadend = () => {
                console.log('hey')
                const allText = reader.result
                console.log(allText);
                let model = parseFileData(allText);
                mainFunc('file', [model])
            }
        } else {
            alert('filereader is not supported')
        }
    }
}

function parseFileData(text) {
    let blocks = text.split('\nfaces\n')
    let vertices = []
    blocks[0].split('\n').slice(1).forEach((line) => {
        line = line.split(', ')
        let vert = new Vertex(line[0], line[1], line[2])
        vertices.push(vert)
    })

    let sumx = 0
    let sumy = 0
    let sumz = 0
    vertices.forEach((item) => {
        sumx += item.x
        sumy += item.y
        sumz += item.z
    })
    let len = vertices.length
    center = new Vertex(sumx/len, sumy/len, sumz/len)

    let faces = []
    let facData = blocks[1].split('\n')
    facData.pop()
    for (let i = 0; i < facData.length; i++) {
        let face = []
        let line = facData[i].split(', ')
        line.forEach((item, index, array) => {array[index] = parseInt(item)})
        for (j = 0; j < line.length; j++) {
            face.push(vertices[line[j]])
        }
        faces.push(face)
    }

    let model = new SomeModel(center, vertices, faces)
    console.log(model)
    return model
}