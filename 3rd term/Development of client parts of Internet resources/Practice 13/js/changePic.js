function changePic(el) {
  let bigImg = document.getElementById("big-image");

  let imgId = el.id.slice(0, -4);

  let src = document.getElementById(imgId).src;
  bigImg.setAttribute("src", src);
}
