import pgdb


def connect():
    hostname = 'localhost'
    username = 'axelcoezard'
    password = '1234'
    database = 'Camping'
    conn = pgdb.connect(host=hostname, port=5432, user=username,
                        password=password, database=database)
    return conn


def disconnect(conn):
    conn.close()


def query(query):
    conn = connect()
    cur = conn.cursor()
    cur.execute(query)
    result = cur.fetchall()
    disconnect(conn)
    return result


def delete_row(table, col_name, col_val):
    conn = connect()
    cur = conn.cursor()
    cur.execute("DELETE FROM \"" + table + "\" WHERE " + col_name + " = " +
                col_val + ";")
    conn.commit()
    disconnect(conn)


def update_row(table, col_name, col_val, values):
    updates = []
    keys = list(values.keys())
    values = list(values.values())
    for key, value in zip(keys, values):
        updates.append(str(key) + "='" + str(value) + "'")
    conn = connect()
    cur = conn.cursor()
    cur.execute("UPDATE \"" + table + "\" SET " + (",".join(updates)
                                                   ) + " WHERE " + col_name + " = " + col_val + ";")
    conn.commit()
    disconnect(conn)


def select_last_insert(table, id):
    conn = connect()
    cur = conn.cursor()
    cur.execute("SELECT MAX(" + id + ") FROM \"" + table + "\";")
    result = cur.fetchall()
    disconnect(conn)
    return result


def insert_choices(table, choices):
    s_keys = "\",\"".join(list(choices.keys()))
    s_placeholders = ",".join(["%s"] * len(choices))
    values = list(choices.values())

    conn = connect()
    cur = conn.cursor()
    cur.execute("INSERT INTO \"" + table +
                "\" (\"" + s_keys + "\") VALUES (" + s_placeholders + ")", values)
    conn.commit()
    disconnect(conn)
