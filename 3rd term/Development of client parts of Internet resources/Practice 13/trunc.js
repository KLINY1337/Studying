function truncate(but, maxlength) {
  let str = but.innerHTML.trim();
  console.log(str);
  if (str.length > maxlength) {
    str = str.slice(0, parseInt(maxlength));
    str += "...";
    but.innerHTML = str;
  }
}
