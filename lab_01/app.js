const mainProcess = (e) => {
    const file = e.target.files[0]
    if (file) {
        //document.querySelector('#file-label').textContent = `${file.name}`
        if (window.FileReader) {
            const reader = new FileReader()
            reader.readAsText(file)
            reader.onloadend = () => {
                const allText = reader.result
                console.log(allText);
                parseFileData(allText);
            }
        } else {
            alert('filereader is not supported')
        }
    }
    else {document.querySelector('.file-label').textContent = `загрузите модель`}
}

function parseFileData(text) {
    const lines = text.split('\n');
    console.log(lines);
    const dots = lines[0].split(';');
    console.log(dots)
}