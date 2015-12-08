
function addEvent(func) {
  if (!document.getElementById | !document.getElementsByTagName) return
  var oldonload=window.onload
  if (typeof window.onload != 'function') {window.onload=func}
  else {window.onload=function() {oldonload(); func()}}
}

function setVisible(element, isVisible) {
	if (element.style) element.style.display=isVisible;
	for (child in element.childNodes) {
		setVisible(child, isVisible);
	}
}


function showHideSolution(soln) {
	if (!soln.style) return;
	var d=soln.style.display;
	var nd = d == 'none'? 'inline' : 'none ';
	setVisible(soln, nd);
	
}


function createAnchor(element) {
	var anchor = document.createElement('a');
	
	anchor.href='#';
	anchor.title='[solution]' ;
	var tn = document.createTextNode(anchor.title);
	anchor.appendChild(tn);
	anchor.className='solutionLink' ;
	anchor.onclick = function() {
		showHideSolution(this.nextSibling);
		return false;
	}	
	return anchor;	
}

function hideElement(sol) {
		setVisible(sol, 'none');
		anchor = createAnchor(sol);
		var p = sol.parentNode;
		p.insertBefore(anchor, sol);
}

function findHidableElements(element) {
	if (element.className == 'solution' || element.className == 'hide')
		hideElement(element);
	else {
		for (var i=element.childNodes.length-1; i>=0; --i) 
			findHidableElements(element.childNodes[i]);
	}
}


function hideSolutions() {
	var element = document.body;
	findHidableElements(document.body);
}



if (document.getElementById && document.getElementsByTagName) { 
	addEvent(hideSolutions);
}
