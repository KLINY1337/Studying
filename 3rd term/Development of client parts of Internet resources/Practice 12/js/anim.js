const test = document.querySelector(".drop-6"),
  rect = test.getBoundingClientRect(),
  rectBox = test.parentNode.getBoundingClientRect(),
  xMax = rectBox.width + rectBox.x - rect.width,
  yMax = rectBox.height + rectBox.y - rect.height,
  maxSpeed = 20;

let x = rect.x,
  y = rect.y,
  xDelta,
  yDelta;

setSpeed();

window.requestAnimationFrame(move);
function move(timestamp) {
  x = x + xDelta;
  y = y + yDelta;
  if (x < rectBox.x || x > xMax) {
    xDelta = -xDelta;
    x = x < rectBox.x ? rectBox.x : xMax;
  }
  if (y < rectBox.y || y > yMax) {
    yDelta = -yDelta;
    y = y < rectBox.y ? rectBox.y : yMax;
  }

  test.style.left = x + "px";
  test.style.top = y + "px";
  window.requestAnimationFrame(move);
}
function setSpeed() {
  xDelta = rand(-maxSpeed, maxSpeed);
  yDelta = rand(-maxSpeed, maxSpeed);
}
function rand(min, max) {
  return Math.random() * (max - min + 1) + min;
}
