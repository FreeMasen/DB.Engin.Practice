use std::io::Read;
use std::io::Write;
use std::fs::File;
use std::fs::Metadata;
use std::fs::FileType;
use std::str;



fn main() {
    let mut contents: Vec<u8>;
    let mut in_file = File::open("logparse.cpp")
        .expect("Unable to open file");
    in_file.read_to_end(&mut contents)
        .expect("Unable to read string");
    let mut out_file = File::create("outfile.txt")
        .expect("Unable to create outfile");
    let contents_str = str::from(contents);
}