package main

import (
	"encoding/csv"
	"io"
	"strconv"

	// "encoding/gob"
	"fmt"
	"log"
	"os"
)

func main() {
    // var asks map[float64]float64

    f, err := os.Open("./data/20200317.csv");

    if err != nil {
        log.Fatal(err)
    }

    /*
    data, err := csv.NewReader(f).ReadAll()
    if err != nil {
	log.Fatal(err)
    }
    */


    /*
    if err := gob.NewDecoder(f).Decode(&asks); err != nil {
        log.Fatal(err)
    }

    for price, size := range asks {
        fmt.Printf("%.6f - %.6f\n", price, size)
    }
    */

    var count int8
    count = 0
    csv_reader := csv.NewReader(f)
    for {
	rec, err := csv_reader.Read()
	if err == io.EOF {
	    break
	}

	if err != nil {
	    log.Fatal(err)
	}

	vol, vol_err := strconv.ParseFloat(rec[3], 64)
	prc, prc_err := strconv.ParseFloat(rec[4], 64)

	if vol_err != nil || prc_err != nil {
	    log.Fatal(vol_err)
	    log.Fatal(prc_err)
	}

	// fmt.Printf("%+v\n", rec[4])
	fmt.Printf("%.6f - %.6f\n", vol, prc)

	count++
	if count > 21 {
	    break
	}
    }
}
