function Accumulator(startingValue) {
  this.value = parseInt(startingValue);

  this.read = function () {
    let result = prompt("Введите аккумулируемое значение");
    console.log(result);
    this.value += parseInt(result);
    console.log(this.value);
  };
}

function handleAccum(startingValue) {
  let counter = document.querySelector(".counter");
  let accum = new Accumulator(startingValue);
  counter.innerHTML = startingValue;
  let button = document.getElementById("btn");
  button.onclick = function () {
    accum.read();
    counter.textContent = accum.value;
  };
}

/*Смарт-контракт — компьютерный алгоритм, предназначенный для заключения и поддержания коммерческих контрактов в технологии блокчейн. Технология смарт-контрактов предлагает программный способ описания взаимоотношений и автоматических действий между сторонами. Одной из особенностей смарт-контракта является его децентрализованная природа и однозначная автоматическая исполняемость — единожды размещенный на децентрализованной платформе, такой контракт будет существовать и исполняться всегда (при наступлении соответствующих событий), пока будет существовать такая платформа.*/
