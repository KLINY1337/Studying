document.getElementById("file-manager-ul").onclick = function (event) {
  //if (event.target.tagName != "LI") return;

  if (event.ctrlKey || event.metaKey) {
    event.target.classList.toggle("selected");
  } else {
    let selected = document
      .getElementById("file-manager-ul")
      .querySelectorAll(".selected");
    for (let elem of selected) {
      elem.classList.remove("selected");
    }
    event.target.classList.add("selected");
  }
};

document.getElementById("file-manager-ul").onmousedown = function () {
  return false;
};

let begunok = document.getElementById("slider").querySelector(".begunok");

begunok.onmousedown = function (event) {
  event.preventDefault();

  let shiftX = event.clientX - begunok.getBoundingClientRect().left;

  document.addEventListener("mousemove", onMouseMove);
  document.addEventListener("mouseup", onMouseUp);

  function onMouseMove(event) {
    let newLeft = event.clientX - shiftX - slider.getBoundingClientRect().left;

    if (newLeft < 0) {
      newLeft = 0;
    }
    let rightEdge = slider.offsetWidth - begunok.offsetWidth;
    if (newLeft > rightEdge) {
      newLeft = rightEdge;
    }

    begunok.style.left = newLeft + "px";
  }

  function onMouseUp() {
    document.removeEventListener("mouseup", onMouseUp);
    document.removeEventListener("mousemove", onMouseMove);
  }
};

begunok.ondragstart = function () {
  return false;
};
