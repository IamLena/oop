let SetOne = function() {
    this.content = []
    this.setContent = function(elements) {
        for (let i = 0; i < elements.length; i++) {
            if (!this.content.includes(elements[i])) {
                this.content.push(elements[i])
            }
        }
    }
    this.getContent = function() {
        return this.content
    }

    this.printContent = function() {
        console.log(this.content)
    }

    this.saveToFile = function(fileName) {
        console.log('saving to file')
    }

    //создать множество, получить множество
    // напечатать, сохранить в файл
    // обьединение, пересечение, вычитание, симметричное вычитание
    // проверка включения
    // декартово произведение
    // отображение - применение к каждому элементу
    // получить мощность - то есть размер
    // добавить элемент
    // удалить элемент
    // sort
}

let mySet = new SetOne()
console.log(mySet)
mySet.setContent([2, 3, 3, 4, 2, 1])
mySet.printContent()
let con = mySet.getContent()
console.log(con)