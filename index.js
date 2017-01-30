var fs = require('fs')
var path = require('path')
var exec = require('child_process').exec;

var utils = {
	get : getMetadata
};
var base = path.dirname(module.filename)+"/Bin/NodeTagLib";

function getMetadata(path,callback){
	try{
		var child=exec(base+' "'+path+'"');
		var json = "";
		child.on('exit',function(e){
			setTimeout(function(){
				callback(JSON.parse(json));
			},5)
		})
		child.stdout.on('data',function(data){
			json = data;
		})
		child.stderr.on('data',function(data){
			console.error(data);
		})
	}catch(e){
		console.error(e);
	}
}

module.exports = utils;
