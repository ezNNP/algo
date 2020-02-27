import java.math.BigInteger
import java.util.*
import kotlin.collections.HashMap
import kotlin.collections.HashSet

val peopleMoney = HashMap<String, BigInteger>()
val peopleCities = HashMap<String, String>()
val citiesMoney = TreeMap<String, BigInteger>()
val moneyCities = TreeMap<BigInteger, HashSet<String>>()
val result = TreeMap<String, Int>()

var lastCityMax = ""
var lastMax = BigInteger.valueOf(-1L)

// Abramovich   London  15000000000
// Deripaska    Moscow  10000000000
// Potanin      Moscow  5000000000
// Berezovsky   London  2500000000
// Khodorkovsky Chita   1000000000

fun increaseCityMoney(city: String, amount: BigInteger) {
    val oldAmount = citiesMoney[city]
    if (citiesMoney.containsKey(city)) {
        citiesMoney[city] = citiesMoney[city]!!.plus(amount)
    } else {
        citiesMoney[city] = amount
    }
    val newAmount = citiesMoney[city]!!
    if (oldAmount != null && moneyCities.containsKey(oldAmount)) {
        moneyCities[oldAmount]!!.remove(city)
        if (moneyCities[oldAmount]!!.size == 0) {
            moneyCities.remove(oldAmount)
        }
    }
    if (!moneyCities.containsKey(newAmount)) {
        moneyCities[newAmount] = HashSet()
    }
    moneyCities[newAmount]!!.add(city)
}

fun changeCity(personName: String, newCity: String) {
    val oldCity = peopleCities[personName]!!
    val amount = peopleMoney[personName]!!
    increaseCityMoney(oldCity, amount.negate())
    increaseCityMoney(newCity, amount)
    peopleCities[personName] = newCity
}

fun checkResult(dayNum: Int, lastDay: Int) {
    if (moneyCities.isNotEmpty() && moneyCities[moneyCities.lastKey()!!]!!.size == 1) {
        if (result.containsKey(moneyCities[moneyCities.lastKey()!!]!!.first())) {
            result[moneyCities[moneyCities.lastKey()!!]!!.first()] =
                    result[moneyCities[moneyCities.lastKey()!!]!!.first()]!!.plus(dayNum - lastDay) // извините за говнокод, мне лень
        } else {
            result[moneyCities[moneyCities.lastKey()!!]!!.first()] = dayNum - lastDay
        }
    }
}

fun main(args: Array<String>) {
    val n = readLine()!!.toInt()
    for (i in 0 until n) {
        val input = readLine()!!.split(" ")
        peopleMoney[input[0]] = BigInteger(input[2])
        peopleCities[input[0]] = input[1]
        increaseCityMoney(input[1], BigInteger(input[2]))
    }
    val input_km = readLine()!!.split(" ")
    var lastDay = 0
    val k = input_km[0].toInt()
    val m = input_km[1].toInt()
    // TODO: sometimes lastDay == currentDay
    // TODO: Check first days and last days
    for (i in 1..m) {
        val input = readLine()!!.split(" ")
        val dayNum = input[0].toInt()
        val name = input[1]
        val toCity = input[2]
        if (lastDay != dayNum) {
            checkResult(dayNum, lastDay)
        }
        changeCity(name, toCity)
        lastDay = dayNum
    }

    checkResult(k, lastDay)

    for (pair in result) {
        println("${pair.key} ${pair.value}")
    }
}